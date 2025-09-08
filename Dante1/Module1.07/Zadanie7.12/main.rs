fn is_prime(a: i32) -> i32 {
    let mut counter = 0;
    if a <= 1 {
        return 0;
    }

    for i in 1..=a {
        if a % i == 0 {
            counter += 1;
        }
    }

    if counter <= 2 {
        return 1;
    }
    0
}

fn is_twin(a: i32, b: i32) -> bool {
    is_prime(a) == 1 && is_prime(b) == 1 && ((a - b == 2) || (b - a) == 2)
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

    if num1 >= num2 + 2 {
        panic!("err");
    }

    let mut counter: usize = 0;
    for i in num1..=num2 - 2 {
        if is_twin(i, i + 2) {
            println!("{} {}", i, i + 2);
            counter += 1;
        }
    }

    if counter == 0 {
        println!("Nothing to show");
    }
}
