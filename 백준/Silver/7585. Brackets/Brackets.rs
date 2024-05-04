use std::io::{stdin, Read};

fn main() {
    let mut out = String::new();
    loop {
        let mut input = String::new();
        stdin().read_line(&mut input).unwrap();
        let mut buf = input.trim_end();
        if buf == "#"{
            break;
        }
        
        let mut stk:Vec<char> = Vec::new();
        let mut ok : bool = true;
        for c in buf.chars(){
            match c {
                '(' => stk.push('('),
                ')' => {
                    if stk.len() > 0 && stk.pop() == Some('('){
                        continue;
                    }else{
                        ok = false;
                    }
                }
                '{' => stk.push('{'),
                '}' => {
                    if stk.len() > 0 && stk.pop() == Some('{'){
                        continue;
                    }else{
                        ok = false;
                    }
                }
                '[' => stk.push('['),
                ']' => {
                    if stk.len() > 0 && stk.pop()  == Some('['){
                        continue;
                    }else{
                        ok = false;
                    }
                }
                _ => {}
            }
        }    
        if stk.len() != 0{
            ok = false;
        }
        if ok{
            out += "Legal\n"
        }else{
            out += "Illegal\n"
        }
    }
    println!("{out}");
    
}
