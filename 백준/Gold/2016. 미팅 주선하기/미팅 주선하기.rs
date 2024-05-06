use std::{io::stdin, vec};

fn main() {
    let mut buf = String::new();
    let mut out = String::new();
    stdin().read_line(&mut buf).expect("fail");
    let tt = buf.trim_end().parse().unwrap();
    for _ in 0..tt{
        let mut boy = vec![vec![0; 5]; 5];
        for i in 1..5{
            buf.clear();
            stdin().read_line(&mut buf).unwrap();
            boy[i] = buf.split_whitespace().map(|s| s.trim().parse().expect("Fail")).collect::<Vec<i32>>();
        }

        let mut girl = vec![vec![0; 5]; 5];
        for i in 0..5{
            buf.clear();
            stdin().read_line(&mut buf).unwrap();
            girl[i] = buf.split_whitespace().map(|x| x.trim().parse().expect("Fail")).collect::<Vec<i32>>();
        }
        
        boy[0] = [6, 7, 8, 9, 10].to_vec();
        let rnk = f(&mut boy, &mut girl);
        let mut ischange : bool = false;
        while next_permutation(&mut boy[0]){
            let r = f(&mut boy, &mut girl);
            if rnk > r{
                ischange = true;
                break;
            }
        }
        if ischange{
            out += "YES\n";
        }else{
            out += "NO\n";
        }
    }
    println!("{out}");
}

fn f(boy :&mut Vec<Vec<i32>>,girl :&mut Vec<Vec<i32>>) -> i32{
    let mut dumped = vec![vec![0; 5]; 5];
    let mut boysgirl = vec![-1; 5];
    let mut girlsboy = vec![-1; 5];
    loop {
        let mut ok : bool = true;
        for i in 0..5 {
            if boysgirl[i] == -1 || girlsboy[i] == -1{
                ok = false
            } 
        }
        if ok{
            break ;
        }

        for i in 0..5{
            if girlsboy[i] != -1{
                continue;
            }
            for b in &girl[i as usize]{
                if dumped[i as usize][*b as usize - 1] == 0{
                    if boysgirl[*b as usize - 1] != -1 &&
                    boy[*b as usize - 1].iter().position(|&r| r == (boysgirl[*b as usize - 1] + 6)).unwrap() 
                    < boy[*b as usize - 1].iter().position(|&r| r == i as i32 + 6).unwrap(){
                        dumped[i as usize][*b as usize -1] = 1;
                    }else{
                        if boysgirl[*b as usize - 1] != -1{
                            girlsboy[boysgirl[*b as usize - 1] as usize] = -1;
                            dumped[boysgirl[*b as usize - 1] as usize][*b as usize - 1] = 1;
                        }
                        boysgirl[*b as usize - 1] = i as i32;
                        girlsboy[i as usize] = *b - 1;
                        break;
                    }
                }
            }
        }
    }
    return boysgirl[0] + 6
}

pub fn next_permutation<T>(arr: &mut [T]) -> bool
where
    T: std::cmp::Ord,
{
    use std::cmp::Ordering;

    // find 1st pair (x, y) from back which satisfies x < y
    let last_ascending = match arr.windows(2).rposition(|w| w[0] < w[1]) {
        Some(i) => i,
        None => {
            arr.reverse();
            return false;
        }
    };

    // In the remaining later segment, find the one which is just
    // larger that the index found above.
    // SAFETY: unwrap_err whill not panic since binary search will
    // will never succeed since we never return equal ordering
    let swap_with = arr[last_ascending + 1..]
        .binary_search_by(|n| match arr[last_ascending].cmp(n) {
            Ordering::Equal => Ordering::Greater,
            ord => ord,
        })
        .unwrap_err();
    arr.swap(last_ascending, last_ascending + swap_with);
    arr[last_ascending + 1..].reverse();
    true
}
