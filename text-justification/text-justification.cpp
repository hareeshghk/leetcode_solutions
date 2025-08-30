#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int num_words = words.size();
        int curWordsSizeWithExtraSpace = 0;
        int currentRowStart = 0;
        for (int idx = 0; idx < num_words; ++idx) {
            // fitted with current word
            if (curWordsSizeWithExtraSpace + words[idx].length() == maxWidth) {
                string curstring = "";
                for (int j = currentRowStart; j < idx; ++j) {
                    curstring += words[j]+" ";
                }
                curstring += words[idx];
                result.push_back(curstring);
                currentRowStart = idx+1;
                curWordsSizeWithExtraSpace = 0;
            }
            // Still space left even after adding word with space on right
            else if (curWordsSizeWithExtraSpace + words[idx].length() + 1 <= maxWidth) {
                curWordsSizeWithExtraSpace += words[idx].length() + 1;
            }
            // Overflowed.
            else {
                int currentRowWords = idx-currentRowStart;
                int wordsSizeWithoutSpaces = curWordsSizeWithExtraSpace-currentRowWords;
                
                int numSpacesPresent = maxWidth-wordsSizeWithoutSpaces;
                
                string curRow = "";
                
                if (currentRowWords == 1) {
                    curRow += words[currentRowStart];
                    for (int i = 0; i < numSpacesPresent; ++i) {
                        curRow += " ";
                    }
                } else {
                    int commonSpacesAfterEachWord =  numSpacesPresent/(currentRowWords-1);
                    int remainingSpaces = numSpacesPresent%(currentRowWords-1);
                
                    string spaceString = "";
                    for (int i = 0; i < commonSpacesAfterEachWord; ++i) {
                        spaceString += " ";
                    }
                
                    for (int i = currentRowStart; i < idx-1; ++i) {
                        curRow += words[i] + spaceString;
                        if (remainingSpaces > 0) {
                            curRow += " ";
                            --remainingSpaces;
                        }
                    }
                    curRow += words[idx-1];
                }
                result.push_back(curRow);
                
                currentRowStart = idx;
                curWordsSizeWithExtraSpace = 0;
                --idx;
            }
        }
        
        // If It was a perfect fit.
        if (currentRowStart == num_words) return result;
        string lastRow = "";
        for (int i = currentRowStart; i < num_words; ++i) {
            lastRow += words[i] + " ";
        }
        
        while (lastRow.length() < maxWidth) {
            lastRow += " ";
        }
        
        result.push_back(lastRow);
        return result;
    }
};
