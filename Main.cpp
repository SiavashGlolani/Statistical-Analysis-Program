#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/audio/player.hpp>
#include <nana/threads/pool.hpp>
#include <nana/gui/timer.hpp>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Test.cpp"
#include "NormalTest.cpp"
#include "UniformTest.cpp"
#include "Test.h"
#include "UniformTest.h"
#include "NormalTest.h"

using namespace std;
using namespace nana;

template <typename type>
void runTests(Test<type>* pTest)
{
    vector <type> histogram = pTest->getHistogram();
    double Max = pTest->getMax(), Min = pTest->getMin(), range = (Max - Min) / 20.0, s = Min;
    int i;

    cout << setprecision(2) << fixed;

    cout << "Minimum: " << pTest->getMin() << std::endl;
    cout << "Maximum: " << pTest->getMax() << std::endl;
    cout << "Mean: " << pTest->getMean() << std::endl;
    cout << "Median: " << pTest->getMedian() << std::endl;
    cout << "Histogram: " << endl;

    for (i = 0; i < histogram.size(); i++)
    {
       cout << "[" << s << ", " << s + range;
       if (i == histogram.size() - 1) cout << "]: "; else cout << "): ";
       cout << histogram[i] << endl;
       s += range;
    }
}

int main()
{

    srand((unsigned)time(NULL));
    //Define a form.
    form fm;

    //nana::timer myTimer(std::chrono::milliseconds(2000));
    
    nana::audio::player playerDo("airplane_chime_x.wav");
    nana::audio::player playerMi("bicycle_bell.wav");
    nana::threads::pool pool(1); //only one thread

    textbox numSamplesBox(fm, rectangle(10, 50, 280, 20));
    numSamplesBox.tip_string("Number of Samples (e.g., 100)");

 

    //Define a label and display a text.
    label lab{ fm, "Hello, <bold blue size=16>Nana C++ Library</>" };
    lab.format(true);
    button redBtn{ fm, "UNIFORM" };
   // redBtn.events().click([] { std::cout << "I was clicked" << std::endl;  });
    //redBtn.events().click([&] { myTimer.reset();  });
    //redBtn.events().click([&] { playerDo.play(); });

    redBtn.events().click([&fm, &numSamplesBox] {   //&playerDo
        //playerDo.play(); // Play sound
        try {
            int numSamples = stoi(numSamplesBox.text()); // Get number of samples
            UniformTest<int> uniformTest(numSamples); // Create test instance

            // Call test methods and output results
            cout << "Uniform Distribution Test: " << endl;
            runTests(&uniformTest);
            // ... other test results ...
        }
        catch (const std::invalid_argument&) {
            // Handle invalid input
            std::cerr << "Please enter a valid number." << std::endl;
        }
        });

    redBtn.bgcolor(color(255, 0, 0));
    

    //Define a button and answer the click event.
    button btn{ fm, "NORMAL" };

    btn.events().click([&fm, &numSamplesBox] {
        try {
            int numSamples = stoi(numSamplesBox.text()); // Get number of samples
            NormalTest<int> NormalTest(numSamples); // Create test instance

            // Call test methods and output results
            cout << "Normal Distribution Test: " << endl;
            runTests(&NormalTest);
            // ... other test results ...
        }
        catch (const std::invalid_argument&) {
            // Handle invalid input
            std::cerr << "Please enter a valid number." << std::endl;
        }
        });

    btn.bgcolor(color(0, 0, 255));
    /*btn.events().click([&] {
        //myTimer.stop();
        fm.close();
        });*/

    //Layout management
    fm.div("vert <AA><<RED><NUM><BB>");
    fm["AA"] << lab;
    fm["BB"] << btn;
    fm["NUM"] << numSamplesBox;
    fm["RED"] << redBtn;
    fm.collocate();


    //Show the form
    fm.show();
    //myTimer.elapse([&] { fm.close(); });
    //myTimer.start();

    //Start to event loop process, it blocks until the form is closed.
    nana::exec();
}