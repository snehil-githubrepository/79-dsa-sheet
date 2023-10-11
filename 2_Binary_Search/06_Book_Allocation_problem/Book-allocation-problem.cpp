class Solution {
    public : 
        //TC: O(N * log(sum(arr[])-max(arr[])+1))
        //SC: O(1)
        int countStudents(vector<int> &arr, int pages) {
            int n = arr.size(); //size of array.
            int students = 1;
            long long pagesStudent = 0;
            for (int i = 0; i < n; i++) {
                if (pagesStudent + arr[i] <= pages) {
                    //add pages to current student
                    pagesStudent += arr[i];
                }
                else {
                    //add pages to next student
                    students++;
                    pagesStudent = arr[i];
                }
            }
            return students;
        }

        int findPages(vector<int>& arr, int n, int m) {
            //book allocation impossible:
            if (m > n) return -1; //student more than the books

            int low = max(arr.begin(), arr.en d());
            int high = accumulate(arr.begin(), arr.end(), 0);
            while (low <= high) {
                int mid = (low + high) / 2;
                int noOfStudents = countStudents(arr, mid);
                if (noOfStudents > m) { //eliminate left half   
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            return low;
        }
};