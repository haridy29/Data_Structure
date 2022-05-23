#include <iostream>

using namespace std;

struct SuffixNode {
    int index;
    int r1;
    int r2;
};

bool compare(SuffixNode node1, SuffixNode node2) {

    if (node1.r1 == node2.r1) {
        if (node1.r2 < node2.r2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (node1.r1 < node2.r1) {
        return true;
    }

    else {
        return false;
    }
}

class SuffixArray {

private:

    SuffixNode *suffixArray;
    char *str;
    int *res;
    int len;

public:

    SuffixArray(char *str) {
        this->str = str;
        this->len = getLength(str);
        this->res = new int[len];
        this->suffixArray = new SuffixNode[len];
    }

    int getLength(char *str) {

        if (str == nullptr) {
            return 0;
        }

        int i = 0;
        while (str[i] != '\0'){
            i++;
        }

        return i;
    }

    void ConstructUsingPrefixDoubling() {

        for (int i = 0; i < len; i++) {
            suffixArray[i].index = i;
            suffixArray[i].r1 = str[i] - 'a';
            if ((i+1) < len) {
                suffixArray[i].r2 = str[i + 1] - 'a';
            }
            else {
                suffixArray[i].r2 = -1;
            }
        }

        merge_sort(suffixArray, 0, len-1);

        int index[len];

        for (int k = 4; k < 2*len; k = k*2) {
            int rank = 0;

            int prevRank = suffixArray[0].r1;
            suffixArray[0].r1 = rank;
            index[suffixArray[0].index] = 0;

            for (int i = 1; i < len; i++) {

                if (suffixArray[i].r1 == prevRank && suffixArray[i].r2 == suffixArray[i-1].r2) {
                    prevRank = suffixArray[i].r1;
                    suffixArray[i].r1 = rank;
                }
                else {
                    prevRank = suffixArray[i].r1;
                    suffixArray[i].r1 = ++rank;
                }
                index[suffixArray[i].index] = i;
            }

            for (int i = 0; i < len; i++) {
                int nextindex = suffixArray[i].index + k/2;
                if (nextindex < len) {
                    suffixArray[i].r2 = suffixArray[index[nextindex]].r1;
                }
                else {
                    suffixArray[i].r2 = -1;
                }
            }

            merge_sort(suffixArray, 0, len-1);
        }

        for (int i = 0; i < len; i++) {
            res[i] = suffixArray[i].index;
        }

    }

    void Print() {
        for (int i = 0; i < len; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    void Merge(SuffixNode arr[],int s,int m,int e){
        int n1=(m-s)+1;
        int n2=e-m;
        SuffixNode arr1[n1],arr2[n2];
        for(int i=0;i<n1;i++) arr1[i]=arr[s+i];
        for(int i=0;i<n2;i++) arr2[i]=arr[m+i+1];
        int ptr1=0,ptr2=0;
        int k=s;
        while(ptr1<n1 && ptr2<n2) {

            if(compare(arr1[ptr1], arr2[ptr2])) {
                arr[k]=arr1[ptr1];
                ptr1++;
            }
            else {
                arr[k]=arr2[ptr2];
                ptr2++;
            }
            k++;
        }

        while(ptr1<n1){
            arr[k]=arr1[ptr1];
            k++;
            ptr1++;
        }

        while(ptr2<n2){
            arr[k]=arr2[ptr2];
            k++;
            ptr2++;
        }

    }

    void merge_sort(SuffixNode arr[],int s,int e){
        if(s>=e) return;
        int m=(s+e)/2;
        merge_sort(arr,s,m);
        merge_sort(arr,m+1,e);
        Merge(arr,s,m,e);
    }
};


int main()
{
    SuffixArray t("ACGACTACGATAAC$");
    t.ConstructUsingPrefixDoubling();
    t.Print(); // Prints:  14 11 12  0  6  3  9 13  1  7  4  2  8 10  5
    return 0;
}
