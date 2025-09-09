fn prime(num: i32) -> i32 {
    if num < 2 {
        return 0;
    }

    let sqrt_num = i32::isqrt(num);
    for i in 2..=sqrt_num {
        if num % i == 0 {
            return 0;
        }
    }

    1
}

fn goldbach(num: i32) -> i32 {
    let mut point: i32 = 0;

    if num % 2 != 0 || num < 4 {
        return 0;
    }

    for i in 2..num {
        if prime(i) == 1 {
            let mut j: i32 = num - i;
            if prime(j) == 1 {
                println!("({}, {})", i, j);
                point = 1;
            }
        }
    }

    point
}

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("err");
    let mut num1: i32 = input.trim().parse().expect("err");

    input.clear();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("err");
    let mut num2: i32 = input.trim().parse().expect("err");

    if num2 < num1 {
        panic!("Incorrect input");
    }

    for i in num1..=num2 {
        if i % 2 == 0 {
            print!("I: {}", i);
            goldbach(i);
            println!();
        }
    }
}
