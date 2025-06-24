fn main()
{
    let mut should_we_continue: bool = true;
    
    let mut result: f64 = 0.0;
    
    while should_we_continue != false
    {
        println!("Enter: ");
        
        let mut number: String = String::new();
        std::io::stdin().read_line(&mut number).expect("Error!!!");
        let number: f64 = number.trim().parse().expect("error");
        
        if number > 0.0
        {
            result = number;
            should_we_continue = false;
        }
        else 
        { 
            println!("Incorrect input!");    
        }
    }
    
    println!("{:.3}\n{:.3}", 2.0 * std::f64::consts::PI * result, std::f64::consts::PI * result * result);
    
    return;
}
