#include <bits/stdc++.h>
using namespace std;

#define ll long long
  
ll _mergeSort(vector<ll>& arr, vector<ll>& temp, ll left, ll right);
ll merge(vector<ll>& arr, vector<ll>& temp, ll left, ll mid,
          ll right);

ll mergeSort(vector<ll>& arr, ll pos, ll array_size)
{
    vector<ll> temp(array_size);
    return _mergeSort(arr, temp, pos, array_size - 1);
}

ll _mergeSort(vector<ll>& arr, vector<ll>& temp, ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) 
    {
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
  
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
  

ll merge(vector<ll>& arr, vector<ll>& temp, ll left, ll mid,
          ll right)
{
    ll i, j, k;
    ll inv_count = 0;
  
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
  
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];
  
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
  
    return inv_count;
}
  
int main()
{
    ll size, in_time, num, f, s;
    cin >> size >> in_time;
    vector<ll> v, v_copy;
    while(cin >> num)
    {
        v.push_back(num);
        v_copy.push_back(num);
    }

    f = mergeSort(v, 0, v.size());
    s = mergeSort(v_copy, 0, in_time);
    cout << f - s << "\n";
    return 0;
}