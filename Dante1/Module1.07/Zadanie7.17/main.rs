fn helper(n: i32) -> f64 {
    if n < 2 {
        return 1.0;
    }
    n as f64 * helper(n - 1)
}

fn my_sin(x: f64, n: i32) -> f64 {
    if n < 0 {
        return -1.0;
    }

    let mut sum: f64 = 0.0;
    for i in 0..=n {
        sum = sum + (f64::powi(-1f64, i) / helper(2 * i + 1)) * f64::powi(x, 2 * i + 1);
    }

    sum
}

fn my_cos(x: f64, n: i32) -> f64 {
    if n < 0 {
        return -1.0;
    }

    let mut sum: f64 = 0.0;
    for i in 0..=n {
        sum = sum + (f64::powi(-1.0, i) / helper(2 * i)) * f64::powi(x, 2 * i);
    }

    sum
}

fn main() {
    let mut input = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Err");
    let kat: f64 = input.trim().parse().expect("Err");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Err");
    let num: i32 = input.trim().parse().expect("Err");

    if num < 0 {
        panic!("Error");
    }

    let mut num1: i32 = 0;
    let mut num2: i32 = 0;

    while f64::abs(my_sin(kat, num1) - f64::sin(kat)) >= 0.0001
    {
        num1 += 1;
    }

    while f64::abs(my_cos(kat, num2) - f64::cos(kat)) >= 0.0001
    {
        num2 += 1;
    }

    println!("{} {}", num1, num2);
}
