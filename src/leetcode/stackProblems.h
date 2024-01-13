#pragma once

#include<iostream>
#include<stack>

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
}
