fn main()
{
    let mut input = String::new();

    print!("Enter smth: ");
    std::io::stdin().read_line(&mut input).expect("Failed to read line");

    let result: String = input.trim().chars().take(30).collect();

    println!("Result is: {}!", result);
}
