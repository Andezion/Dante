fn main()
{
    println!("Enter your number: ");
    
    let mut num_float: String = String::new();
    std::io::stdin().read_line(&mut num_float).expect("Incorrect string");
    
    let num_float: f32 = num_float.trim().parse().expect("Incorrect float number");
    
    println!("Enter precision: ");
    
    let mut precision: String = String::new();
    std::io::stdin().read_line(&mut precision).expect("Incorrect string");
    
    let precision: usize = precision.trim().parse().expect("Incorrect int number");
    
    println!("{:.1$}", num_float, precision);
    
    return;
}
