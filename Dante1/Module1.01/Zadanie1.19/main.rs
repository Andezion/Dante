fn main() 
{
    println!("Enter x: ");
    
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).expect("Failed to read line");
    
    let x: f64 = x.trim().parse().expect("Failed to parse into a number");
    
    println!("Result is: {:.6}", 2.0 * x.powi(3) - 4.0 * x.powi(2) + 3.0 * x - 7.0);
    
    return;
}
