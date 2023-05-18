#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num_frames, num_pages, page_faults = 0;
    cout << "Enter the number of frames: ";
    cin >> num_frames;
    cout << "Enter the number of pages: ";
    cin >> num_pages;
    int pages[num_pages];
    cout << "Enter the page references: ";
    for (int i = 0; i < num_pages; i++) {
        cin >> pages[i];
    }

    int frames[num_frames];
    bool is_page_present[num_pages] = { false };
    int next_use[num_frames];

    cout << "Reference String\tFrames\t\tPage Fault\n";

    for (int i = 0; i < num_pages; i++) {
        cout << pages[i] << "\t\t\t";
        if (!is_page_present[pages[i]]) {
            if (page_faults < num_frames) {
                frames[page_faults] = pages[i];
                next_use[page_faults] = find(pages + i + 1, pages + num_pages, pages[i]) - pages;
                
            } else {
                int index = 0;
                for (int j = 1; j < num_frames; j++) {
                    if (next_use[j] > next_use[index]) {
                        index = j;
                    }
                }
                //cout<<index<<endl;
                is_page_present[frames[index]] = false;
                frames[index] = pages[i];
                next_use[index] = find(pages + i + 1, pages + num_pages, pages[i]) - pages;
            }
            page_faults++;
            is_page_present[pages[i]] = true;
            for (int j = 0; j < num_frames; j++) {
                if (j < page_faults) {
                    cout << frames[j] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << "\t\tMiss";
        } else {
            for (int j = 0; j < num_frames; j++) {
                if (j < page_faults) {
                    cout << frames[j] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << "\t\tHit";
        }
        cout << endl;
    }

    cout << "Page faults: " << page_faults << endl;
    return 0;
}


