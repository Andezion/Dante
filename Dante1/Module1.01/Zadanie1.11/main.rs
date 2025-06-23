fn main()
{
    println!("Enter your number: ");

    let mut user_input = String::new();
    std::io::stdin().read_line(&mut user_input).expect("Failed to read line");

    let user_input: i32 = user_input.trim().parse().expect("Not a number");

    println!("Your number is: {user_input}");

    return;
}
