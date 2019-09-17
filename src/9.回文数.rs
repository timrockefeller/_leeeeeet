/*
 * @lc app=leetcode.cn id=9 lang=rust
 *
 * [9] 回文数
 */
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if (x < 0) {
            return false;
        }
        let mut count:i32 = i32::from(f64::from(x).log10() )+ 1; 
        while(count>1){
            let ten:i32=10;
            if(x%10 != (x/ten.pow(u32::from(count-1)))){
                return false;
            }
            x = ((x - x % 10) / 10) % (ten.pow(u32::from(count - 2)));
            count = count - 2;
        }
        return true;
    }
}

