/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function(nums1, nums2) {
    let ans = [];

    let st = [];
    let mp = new  Map();

    //map creation on nums 2
    for(let i = 0; i < nums2.length; i++) {
        while(st.length > 0 && nums2[i] > st[st.length - 1]) {
            mp.set(st.pop(), nums2[i]);
        }
        st.push(nums2[i]);
    }

    //for el without NGE, set it as -1
    while(st.length > 0) {
        mp.set(st.pop(), -1);
    }

    //Retrieve NGE for nums1 from maps
    for(let i = 0; i < nums1.length ; i++) {
        ans.push(mp.get(nums1[i]));
    }

    return ans;
};