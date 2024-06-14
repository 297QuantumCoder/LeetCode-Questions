# Subsequence Check

## Problem Statement

Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

### Examples

#### Example 1

- **Input:** 
  - `s = "abc"`
  - `t = "ahbgdc"`
- **Output:** `true`
- **Explanation:** By removing 'h', 'b', 'g', and 'd' from "ahbgdc", we get "abc".

#### Example 2

- **Input:** 
  - `s = "axc"`
  - `t = "ahbgdc"`
- **Output:** `false`
- **Explanation:** There is no way to form "axc" from "ahbgdc" by deleting characters without changing the order of the remaining characters.

### Constraints

- \(0 \leq s.\text{length} \leq 100\)
- \(0 \leq t.\text{length} \leq 10^4\)
- `s` and `t` consist only of lowercase English letters.

### Follow-up

Suppose there are lots of incoming `s` strings, say `s1`, `s2`, ..., `sk` where \(k \geq 10^9\), and you want to check one by one to see if `t` has its subsequence. In this scenario, how would you change your code?