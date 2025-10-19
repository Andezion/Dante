fn clamp(x: i32, mut lo: i32, mut hi: i32) -> i32 {
    if lo > hi {
        let temp = lo;
        lo = hi;
        hi = temp;
    }

    if x > lo && x < hi {
        return x;
    }
    else if x <= lo {
        return lo;
    }
    hi
}

fn main() {
    let mut input: String = String::new();

    input.clear();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let x: i32 = input.trim().parse().expect("Error");


    input.clear();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let lo: i32 = input.trim().parse().expect("Error");

    input.clear();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Error");
    let hi: i32 = input.trim().parse().expect("Error");

    println!("Result is: {}", clamp(x, lo, hi));
}
