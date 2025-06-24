fn main()
{
    println!("Enter: ");
    
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    
    let input: i32 = input.trim().parse().expect("Incorrect number");
    
    if !input.is_negative() && !input.is_positive()
    {
        println!("Equal to zero");
    }
    else 
    { 
        println!("Not equal to zero");    
    }
    
    return;
}
