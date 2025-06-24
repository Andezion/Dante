fn main()
{
    println!("Enter number: ");
    
    let mut number : String = String::new();
    std::io::stdin().read_line(&mut number).expect("Incorrect string input");
    
    let number: f32 = number.trim().parse().expect("Incorrect number parsing");
    
    let _number_2: f32;
    if number <= 50.0
    {
        _number_2 = number * 0.5;
    }
    else if number <= 150.0
    {
        _number_2 = 50.0 * 0.50 + (number - 50.0) * 0.75;
    }
    else if number <= 250.0
    {
        _number_2 = 50.0 * 0.50 + 100.0 * 0.75 + (number - 150.0) * 1.20;
    }
    else
    {
        _number_2 = 50.0 * 0.50 + 100.0 * 0.75 + 100.0 * 1.20 + (number - 250.0) * 1.50;
    }
    
    println!("Result is: {:.6}", _number_2 * (1.0 + 0.22));
    
    return;
}
