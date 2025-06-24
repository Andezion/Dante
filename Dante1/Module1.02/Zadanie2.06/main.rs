fn main()
{
    println!("Enter first number: ");
    let mut number_one :String = String::new();
    std::io::stdin().read_line(&mut number_one).expect("Incorrect input in String for number one");
    
    let number_one: i32 = number_one.trim().parse().expect("Error in parsing number_one");
    
    println!("Enter number two:");
    let mut number_two: String = String::new();
    std::io::stdin().read_line(&mut number_two).expect("Incorrect input in String for number two");
    
    let number_two: i32 = number_two.trim().parse().expect("Error in parsing number_two");
    if number_two == 0
    {
        panic!("Error! Division by 0!");
    }
    
    
    if number_one % number_two == 0 && number_one > number_two
    {
        println!("{} is divisible by {}", number_one, number_two);
    }
    else 
    { 
        println!("{} is not divisible by {}", number_one, number_two);
    }
    
    return;
}
