use std::{io::{stdin, Read}};

fn main() {
    let mut buf = String::new();
    stdin().read_to_string(&mut buf).expect("Fail to read");
    let mut buf = buf.split_ascii_whitespace().flat_map(str::parse::<usize>);
    let n  = buf.next().unwrap();
    
    let mut ans = 0;
    let mut dp = vec![0; 31];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for i in 3..n+1{
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    ans = dp[n];
    if n & 1 == 1 {
        ans += dp[n / 2];
    }else{
        ans += dp[n / 2 + 1]
    }
    ans /= 2;
    if n == 1 {
        ans += 1
    }
    println!("{}", ans);
}
