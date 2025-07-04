fn test1(a: i32) -> i32
{
    a
}

fn main()
{
    let mut input: String = String::new();

    println!("Enter: ");

    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let number: i32 = input.trim().parse().expect("Incorrect parsing");

    println!("Result is: {}", test1(number));
}
