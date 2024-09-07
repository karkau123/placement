// Credtis @Vedant_Agarwal
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
const int mod = 1e9+7;

/*
Inplace: Uses a constant amount of extra space.
Stable: Maintains the relative order of equal elements.
Adaptive: Takes advantage of existing order in the input.
Online: Can process data as it becomes available.
*/

/*
Ranking of Sorting Algorithms (Average Case Time Complexity)
1.	Merge Sort - O(NlogN)
2.	Quick Sort - O(NlogN)
3.	Heap Sort - O(NlogN)
4.	Counting Sort - O(N+M)  (M is the range of input values)
5.	Bucket Sort - O(N + k) (k is the number of buckets)
6.	Radix Sort - O(N k) (k is the number of digits)
7.	Insertion Sort - O(N^2)
8.	Bubble Sort - O(N^2)
9.	Selection Sort - O(N^2)
*/


/*
Selection Sort - Searches for the minimum element in the array and 
               swaps it with the element at the starting index.

Time Complexity:
Best: O(N²)
Average: O(N²)
Worst: O(N²)

Space Complexity:
O(1) (Inplace)

Inplace: Yes
Stable: No
Adaptive: No
Online: No
*/
void selectionSort(vector<int>&a,int n){
     for(int i=0;i<n-1;i++){
          int mini=i;
          for(int j=i+1;j<n;j++){
               if(a[j]<a[mini]) mini=j;
          }
          if(mini!=i) swap(a[i],a[mini]);
     }
}

/*
Bubble Sort - Swaps adjacent elements to move the largest unsorted element 
          to its correct position.

Best: O(N) (when the array is already sorted)
Average: O(N²)
Worst: O(N²) (when the array is reverse sorted)

Space Complexity:
O(1) (Inplace)

Inplace: Yes
Stable: Yes
Adaptive: Yes
Online: No
*/
void bubbleSort(vector<int>&a,int n){
     for(int i=0;i<n-1;i++){
          int didSwap=0;
          for(int j=0;j<n-1-i;j++){
               if(a[j]>a[j+1]) {
                    swap(a[j],a[j+1]);
                    didSwap=1;
               }
          }
          if(!didSwap) break;
     }
}

/*
Inserion Sort - Inserts each element into its correct position in the 
          sorted part of the array.

Best: O(N) (when the array is already sorted)
Average: O(N²)
Worst: O(N²) (when the array is reverse sorted)

Space Complexity:
O(1) (Inplace)

Inplace: Yes
Stable: Yes
Adaptive: Yes
Online: Yes
*/
void insertionSort(vector<int>&a,int n){
     for(int i=0;i<n;i++){
          int j=i;
          while(j>0 && a[j-1]>a[j]){
               swap(a[j-1],a[j]);
               j--;
          }
     }
}

/*
Merge Sort - Divides the array into smaller parts and merges them in sorted order.
# Divide & Conquer

Best: O(N log N)
Average: O(N log N)
Worst: O(N log N)

Space Complexity:
O(N) (Not Inplace)

Inplace: No
Stable: Yes
Adaptive: No
Online: No
*/
void merge(vector<int>&a,int low,int mid,int high){
     int left=low,right=mid+1;
     vector<int>temp;
     while(left<=mid && right<=high){
          if(a[left]<=a[right]){
               temp.push_back(a[left]);
               left++;
          }
          else{
               temp.push_back(a[right]);
               right++;
          }
     }
     while(left<=mid){
          temp.push_back(a[left]);
          left++;
     }
     while(right<=high){
          temp.push_back(a[right]);
          right++;
     }
     for(int i=low;i<=high;i++){
          a[i]=temp[i-low];
     }
}
void mergeSort(vector<int>&a,int low,int high){
     if(low>=high) return;
     int mid=low+(high-low)/2;
     mergeSort(a,low,mid);
     mergeSort(a,mid+1,high);
     merge(a,low,mid,high);
}

/*
Quick Sort - Picks a pivot and partitions the array such that elements smaller than 
          the pivot are on the left and larger on the right.
# Divide & Conquer

Best: O(N log N)
Average: O(N log N)
Worst: O(N²) (when the pivot selection is poor, like reverse sorted array)

Space Complexity:
O(log N) (stack space due to recursion)

Inplace: Yes
Stable: No
Adaptive: No
Online: No
*/
int partition(vector<int>&a,int low,int high){
     int pivot=a[low];
     int i=low,j=high;
     while(i<j){
          while(i<=high && a[i]<=pivot) i++;
          while(j>=low && a[j]>pivot) j--;
          if(i<j) swap(a[i],a[j]);
     }
     swap(a[low],a[j]);
     return j;
}
void quickSort(vector<int>&a,int low,int high){
     if(low>=high) return;
     int pIdx=partition(a,low,high);
     quickSort(a,low,pIdx-1);
     quickSort(a,pIdx+1,high);
}

/*
Counting Sort - Counts the frequency of each element and places them accordingly.
# Non-Comparision Algo
# When the range of input values is small compared to the number of elements

Best: O(N + M)
Average: O(N + M)
Worst: O(N + M) (where M is the range of the input values)

Space Complexity:
O(M) (due to additional counting array)

Inplace: No
Stable: Yes
Adaptive: No
Online: No
*/
void countingSort1(vector<int>&a,int n){
     int maxi=*max_element(a.begin(), a.end());
     int mini=*min_element(a.begin(), a.end());
     int range=maxi-mini+1;
     vector<int>freq(range,0);
     for(auto it:a) freq[it-mini]++;
     int k=0;
     for(int i=0;i<range;i++){
          for(int j=0;j<freq[i];j++){
               a[k]=(i+mini);
               k++;
          }
     }
}
vector<int> countingSort2(vector<int>&a, int n){
     int maxi=*max_element(a.begin(),a.end());
     vector<int>count(maxi+1,0);
     for (int i=0;i<n;i++) count[a[i]]++;
 
     for (int i=1;i<=maxi;i++)
         count[i]+=count[i-1];

     vector<int> res(n);
     for (int i=n-1;i>=0;i--) {
         res[count[a[i]]-1] = a[i];
         count[a[i]]--;
     }
     return a=res;
}
/*
Bucket Sort - Divides elements into buckets and sorts each bucket.
# Mostly Used for float datatype


Best: O(N + k) (k is the number of buckets)
Average: O(N + k)
Worst: O(N²) (if all elements end up in the same bucket)

Space Complexity:
O(N + k) (space for buckets)

Inplace: No
Stable: Yes (depends on how the sub-sorting is handled)
Adaptive: No
Online: No
*/
vector<float> bucketSort(vector<float> &a,int n) {
     if (a.empty()) return {};

     float maxElement = *max_element(a.begin(), a.end()); 
     int maxIndex = static_cast<int>(maxElement * a.size());
     int bucketSize = maxIndex + 1;
 
     vector<vector<float>> buckets(bucketSize);
     for (int i = 0; i < n; i++) {
          int index = static_cast<int>(a[i] * a.size());
          auto pos = upper_bound(buckets[index].begin(), buckets[index].end(), a[i]);
          buckets[index].insert(pos, a[i]);
     }
 
     vector<float> res;
     for (int i = 0; i < bucketSize; i++) {
          for (float element : buckets[i]) {
              res.push_back(element);
          }
     }
     return a=res;
}


/*
Radix Sort - Processes elements digit by digit starting from the least significant digit.

Time Complexity:
Best: O(Nk) (where k is the number of digits in the maximum number)
Average: O(Nk)
Worst: O(Nk)

Space Complexity:
O(N + k) (for the counting array in each digit-level sorting)

Inplace: No
Stable: Yes
Adaptive: No
Online: No
*/
void countSort(vector<int>&a, int n, int exp){
     vector<int> res(n);
     int count[10] = {0};
     for (int i = 0; i < n; i++)
         count[(a[i] / exp) % 10]++;
 
     for (int i = 1; i < 10; i++)
         count[i] += count[i - 1];
 
     for (int i = n - 1; i >= 0; i--) {
         res[count[(a[i] / exp) % 10] - 1] = a[i];
         count[(a[i] / exp) % 10]--;
     }
     a=res;
}
void radixSort(vector<int>&a,int n){
     int m = *max_element(a.begin(), a.end()); 
     for (int exp = 1; m / exp > 0; exp *= 10)
         countSort(a, n, exp);
}

/*
Heap Sort - Builds a heap and repeatedly extracts the maximum element to sort the array.

Time Complexity:
Best: O(N log N)
Average: O(N log N)
Worst: O(N log N)

Space Complexity:
O(1) (Inplace)

Inplace: Yes
Stable: No
Adaptive: No
Online: No
*/
void heapify(vector<int>&a,int n,int i){
     int largest=i;
     int left=2*i+1;
     int right=2*i+2;
     if(left<n && a[largest]<a[left]){
         largest=left;
     }
     if(right<n && a[largest]<a[right]){
         largest=right;
     }
     if(largest!=i){
         swap(a[largest],a[i]);
         heapify(a,largest,n);
     }
}

void heapSort(vector<int>&a,int n){
     for (int i = n / 2 - 1; i >= 0; i--)
         heapify(a, n, i);
 
     for (int i = n - 1; i > 0; i--) {
         swap(a[0], a[i]);
         heapify(a, i, 0);
     }
}

/*
Sort By Frequency - Sorts elements by the frequency of occurrence.

Time Complexity:
O(N log N) (due to sorting the frequency map)

Space Complexity:
O(N) (due to extra space for frequency count and result storage)

Inplace: No (depends on the implementation)
Stable: Yes (if sorting by first occurrence)
Adaptive: No
Online: No
*/
vector<int> sortByFreq(vector<int>&a,int n){
     map<int,int>mp;
     for(int i=0;i<n;i++) mp[a[i]]++;
     vector<pair<int,int>>v;
     for(auto it:mp) v.push_back({it.first,it.second});
     
     sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){
         if(a.second!=b.second)
         return a.second>b.second;
         else
         return a.first<b.first;
     });
 
     vector<int>ans;
     for(int i=0;i<v.size();i++){
          ans.push_back(v[i].first);
     }
     return  a=ans;
}

int main(){
     vector<int>a={1,5,32,545,5,1,0};
     // selectionSort(a,7);
     // bubbleSort(a,7);
     // insertionSort(a,7);
     // mergeSort(a,0,6);
     // quickSort(a,0,6);
     // countingSort1(a,7);
     // countingSort2(a,7);
     // heapSort(a,7);
     // bucketSort(a,7);
     // radixSort(a,7);
     // heapSort(a,7);
     // sortByFreq(a,7);
     for(auto it:a) cout<<it<<" ";
     return 0;
}