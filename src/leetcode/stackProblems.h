#pragma once

#include<iostream>
#include<stack>
#include<vector>
#include<queue>

namespace leetcode {


/* Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path. */

/* In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names. */

/* The canonical path should have the following format: */

/* The path starts with a single slash '/'. */
/* Any two directories are separated by a single slash '/'. */
/* The path does not end with a trailing '/'. */
/* The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..') */
/* Return the simplified canonical path. */



/* Example 1: */

/* Input: path = "/home/" */
/* Output: "/home" */
/* Explanation: Note that there is no trailing slash after the last directory name. */
/* Example 2: */

/* Input: path = "/../" */
/* Output: "/" */
/* Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go. */
/* Example 3: */

/* Input: path = "/home//foo/" */
/* Output: "/home/foo" */
/* Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one. */
    std::string simplifyPath( std::string path );



    // Make string great

    // Given a string s of lower and upper case English letters.

    // A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

    // 0 <= i <= s.length - 2
    // s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
    // To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string b    // ecomes good.

    // Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

    // Notice that an empty string is also good.

    // Example 1:

    // Input: s = "leEeetcode"
    // Output: "leetcode"
    // Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
    // Example 2:

    // Input: s = "abBAcC"
    // Output: ""
    // Explanation: We have many possible scenarios, and all lead to the same answer. For example:
    // "abBAcC" --> "aAcC" --> "cC" --> ""
    // "abBAcC" --> "abBA" --> "aA" --> ""
    // Example 3:

    // Input: s = "s"
    // Output: "s"
    std::string makeGood( std::string s);



    // 933 - number f recent calls
    // You have a RecentCounter class which counts the number of recent requests within a certain time frame.

    // Implement the RecentCounter class:

    // RecentCounter() Initializes the counter with zero recent requests.
    // int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in     // the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3    // 000, t].
    // It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.

    // Example 1:

    // Input
    // ["RecentCounter", "ping", "ping", "ping", "ping"]
    // [[], [1], [100], [3001], [3002]]
    // Output
    // [null, 1, 2, 3, 3]

    // Explanation
    // RecentCounter recentCounter = new RecentCounter();
    // recentCounter.ping(1);     // requests = [1], range is [-2999,1], return 1
    // recentCounter.ping(100);   // requests = [1, 100], range is [-2900,100], return 2
    // recentCounter.ping(3001);  // requests = [1, 100, 3001], range is [1,3001], return 3
    // recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
    class RecentCounter {
        std::queue<int> q_;

    public:
        RecentCounter() {}

        int ping(int t) {
            q_.push( t );

            while( q_.back() - 3000 > q_.front() ) {
                q_.pop();
            }

            return q_.size();
        }
    };


    // moving avarage
    // Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

    // Implement the MovingAverage class:

    // MovingAverage(int size) Initializes the object with the size of the window size.
    // double next(int val) Returns the moving average of the last size values of the stream.


    // Example 1:

    // Input
    // ["MovingAverage", "next", "next", "next", "next"]
    // [[3], [1], [10], [3], [5]]
    // Output
    // [null, 1.0, 5.5, 4.66667, 6.0]

    // Explanation
    // MovingAverage movingAverage = new MovingAverage(3);
    // movingAverage.next(1); // return 1.0 = 1 / 1
    // movingAverage.next(10); // return 5.5 = (1 + 10) / 2
    // movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
    // movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3

    template< typename T >
    struct queue_iter : public std::queue< T > {
        using std::queue<T>::c;
        auto begin() { return c.begin(); }
        auto end() { return c.end(); }
    };

    class MovingAverage {
    public:
        queue_iter< int > q_;
        int size_;

        MovingAverage(int size) : size_{ size }{}

        double next(int val) {
            q_.push( val );
            while( q_.size() > size_ ) {
                q_.pop();
            }

            double total = 0;
            for( auto el : q_ ) {
                total += el;
            }

            return total / q_.size();
        }
    };

}
