fn sqrt(number: i32) -> i32
{
    number * number
}

fn main()
{
    let mut input: String = String::new();
    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: i32 = input.trim().parse().expect("Incorrect parsing");

    println!("Result is: {}", sqrt(number));
}
