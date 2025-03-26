#You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

#"1" -> 'A'

#"2" -> 'B'

#...

#"25" -> 'Y'

#"26" -> 'Z'

#However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

#For example, "11106" can be decoded into:

#"AAJF" with the grouping (1, 1, 10, 6)
#"KJF" with the grouping (11, 10, 6)
#The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
#Note: there may be strings that are impossible to decode.

#Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

#The test cases are generated so that the answer fits in a 32-bit integer.

class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':  
            return 0  
        
        n = len(s)
        dp = [0] * (n + 1)  
        dp[0] = 1  
        dp[1] = 1 if s[0] != '0' else 0  

        for i in range(2, n + 1):
            one_digit = int(s[i-1])  
            two_digit = int(s[i-2:i])  
            
            if 1 <= one_digit <= 9:
                dp[i] += dp[i - 1]  

            if 10 <= two_digit <= 26:
                dp[i] += dp[i - 2]  

        return dp[n]

