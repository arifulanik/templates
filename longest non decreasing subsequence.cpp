#include<bits/stdc++.h>


#define            ll              long long

using namespace std;


string height;
int s[100009];

int binary_search(int first, int last, char  x) {

    while(last > first)
    {
        int mid = first + (last - first) / 2;
        if(height[s[mid]] > x)
            last = mid;
        else
            first = mid + 1;
    }

    return first; /* or last */
}

int lis(int n) {

    int i, k, index;

    memset(s, 0, sizeof(s));

    index = 1;
    s[1] = 0; /* s[i] = 0 is the index of the element that ends an increasing sequence of length  i = 1 */

    for (i = 1; i < n; i++) {

        if (height[i] >= height[s[index]]) { /* larger element, extend the sequence */

            index++; /* increase the length of my subsequence */
            s[index] = i; /* the current doll ends my subsequence */

        }
        /* else find the smallest element in s >= a[i], basically insert a[i] in s such that s stays sorted */
        else {
            k = binary_search(1, index, height[i]);

            if (height[s[k]] >= height[i]) { /* if truly >= greater */
                s[k] = i;
            }
        }
    }
    return index;
}

void solve()
{
	int n,x,ans=0;
	cin>>n;
    cin>>height;
    ans=lis(n);
    ///cout<<ans<<endl;
	cout<<n-ans<<endl;
   

}

main()
{
    

       int t,cs=1;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
}
