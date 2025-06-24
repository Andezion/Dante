fn main()
{
    println!("Enter: ");
    
    let mut number: String = String::new();
    std::io::stdin().read_line(&mut number).expect("Incorrect input");
    let mut number: f64 = number.trim().parse().expect("Incorrect parsing");
    
    let mut temp: f64 = number;
    
    while number > 9.0
    {
        number = number / 10.0;
    }
    
    println!("{number} {}", temp % 10.0);
     
    return;
}
