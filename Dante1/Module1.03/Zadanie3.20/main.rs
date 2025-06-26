fn main()
{
    let mut input: String = String::new();
    
    println!("Enter: ");
    
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Error");
    let mut number_one: i32 = input.trim().parse().expect("Error");
    
    println!("Enter: ");
    
    input.clear();
    std::io::stdin().read_line(&mut input).expect("Error");
    let number_two: i32 = input.trim().parse().expect("Error");
    
    if number_one > number_two
    {
        println!("Incorrect input");
        return;
    }
    
    while number_one != number_two + 1
    {
        println!("{} ", number_one);
        number_one += 1;
    }
    
    return;
}
