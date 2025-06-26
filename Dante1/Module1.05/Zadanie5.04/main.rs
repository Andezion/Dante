fn main()
{
    let mut input = String::new();

    println!("Enter smth: ");
    std::io::stdin().read_line(&mut input).expect("Failed to read line");
    
    println!("Result is: {}!", input.len() - 1);
}
