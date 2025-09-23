class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t start1 = 0, start2 = 0;
        while (start1 < version1.size() || start2 < version2.size()) {
            size_t end1 = version1.find('.', start1);
            size_t end2 = version2.find('.', start2);
            
            int num1 = 0, num2 = 0;
            if (start1 < version1.size())
                num1 = stoi(version1.substr(start1, (end1 == string::npos ? version1.size() : end1) - start1));
            if (start2 < version2.size())
                num2 = stoi(version2.substr(start2, (end2 == string::npos ? version2.size() : end2) - start2));
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            
            start1 = (end1 == string::npos ? version1.size() : end1 + 1);
            start2 = (end2 == string::npos ? version2.size() : end2 + 1);
        }
        return 0;
    }
};
