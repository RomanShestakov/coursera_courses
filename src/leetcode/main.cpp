#include<vector>
#include<iostream>


int largestSumOfsubarrays1( const std::vector<int>& nums, int k) {

    int l = 0;
    int sum = 0;
    int answ = 0;

    for(int r = 0; r < nums.size(); r++) {

        if( r < k ) {
            sum += nums[ r ];
            std::cout<< "1 sum " << sum << " r " << r << std::endl;
        }
        else {
            std::cout<< "2 before sum " << sum << " " << nums[ r ] << " " << nums[ l ] << std::endl;
            sum += nums[ r ] - nums[ l++ ];
            std::cout<< "2 after sum " << sum <<  " l " << l - 1 << std::endl;
        }

        answ = std::max( sum, answ);
    }

    return sum;
}


//  {3, -1, 4,12,-8,5,6};

// 18
// 18 -8 - 3 = 7
// 7 + 5 + 1 = 13
// 13 + 6 -4 = 15

int main() {

    std::vector<int> v = {3, -1, 4,12,-8,5,6};
    auto a = largestSumOfsubarrays1(v, 4);

    std::cout << "answer: " << a << std::endl;
    return 0;
}
