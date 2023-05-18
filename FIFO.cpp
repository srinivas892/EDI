#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n_frames, n_pages, page_faults = 0;
    cout << "Enter the number of frames: ";
    cin >> n_frames;
    cout << "Enter the number of pages: ";
    cin >> n_pages;
    int pages[n_pages];
    cout << "Enter the page references: ";
    for (int i = 0; i < n_pages; i++) {
        cin >> pages[i];
    }

    queue<int> frame;
    bool is_page_present[n_pages] = { false };

    cout << "Reference String\tFrames\t\tPage Fault\n";
    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < n_pages; i++) {
        cout << pages[i] << "\t\t\t";
        if (!is_page_present[pages[i]]) {
            if (frame.size() == n_frames) {
                int removed_page = frame.front();
                frame.pop();
                is_page_present[removed_page] = false;
            }
            frame.push(pages[i]);
            is_page_present[pages[i]] = true;
            
            for (int j = 0; j < frame.size(); j++) {
                int temp = frame.front();
                frame.pop();
                cout << temp << " ";
                frame.push(temp);
            }
            page_faults++;
            cout << "\t\tMiss";
        } else {
            
            for (int j = 0; j < frame.size(); j++) {
                int temp = frame.front();
                frame.pop();
                cout << temp << " ";
                frame.push(temp);
            }
            cout << "\t\tHit";
        }
        cout << endl;
    }
    
    cout << "\nNumber of page faults: " << page_faults << endl;
    return 0;
}
