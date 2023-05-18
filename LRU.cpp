#include <iostream>
#include <algorithm>
#include <deque>
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

    deque<int> frame_deque;
    bool is_page_present[num_pages] = { false };

    cout << "Reference String\tFrames\t\tPage Fault\n";

    for (int i = 0; i < num_pages; i++) {
        cout << pages[i] << "\t\t\t";
        if (!is_page_present[pages[i]]) {
            if (frame_deque.size() == num_frames) {
                int removed_page = frame_deque.back();
                frame_deque.pop_back();
                is_page_present[removed_page] = false;
            }
            frame_deque.push_front(pages[i]);
            is_page_present[pages[i]] = true;
            page_faults++;
            
            for (int j = 0; j < num_frames; j++) {
                if (j < frame_deque.size()) {
                    cout << frame_deque[j] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << "\t\t";
            cout << "Fault";
            cout << endl;
            
        } else {
            frame_deque.erase(find(frame_deque.begin(), frame_deque.end(), pages[i]));
            frame_deque.push_front(pages[i]);
            for (int j = 0; j < num_frames; j++) {
                if (j < frame_deque.size()) {
                    cout << frame_deque[j] << " ";
                } else {
                    cout << "  ";
                }
            }
            cout << "\t\t";
            cout << "Hit";
            cout << endl;
        }
        // for (int j = 0; j < num_frames; j++) {
        //     if (j < frame_deque.size()) {
        //         cout << frame_deque[j] << " ";
        //     } else {
        //         cout << "  ";
        //     }
        // }
        // cout << "\t\t";
        // if (!is_page_present[pages[i]]) {
        //     cout << "Fault";
        // } else {
        //     cout << "Hit";
        // }
        // cout << endl;
    }

    cout << "\nNumber of page faults: " << page_faults << endl;
    return 0;
}