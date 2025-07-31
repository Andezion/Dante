pub fn marks_counter(s: &str, uppercase: &mut i32,
                     lowercase: &mut i32,
                     whitespace: &mut i32,) -> i32 {

    if s.is_empty() {
        return 1;
    }

    let mut c1: i32 = 0;
    let mut c2: i32 = 0;
    let mut c3: i32 = 0;

    for c in s.chars() {
        if c.is_uppercase() {
            c1 += 1;
        }
        else if c.is_lowercase() {
            c2 += 1;
        }
        else if c.is_whitespace() {
            c3 += 1;
        }
        else {
            // ignore
        }
    }

    *uppercase = c1;
    *lowercase = c2;
    *whitespace = c3;

    0
}

fn main() {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");

    let mut uppercase: i32 = 0;
    let mut lowercase: i32 = 0;
    let mut whitespaces: i32 = 0;

    if marks_counter(&*input, &mut uppercase, &mut lowercase, &mut whitespaces) != 0 {
        panic!("u r noob");
    }

    println!("{0} {1} {2}", uppercase, lowercase, whitespaces);
}
