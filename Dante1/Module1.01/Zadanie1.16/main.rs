fn main()
{
    println!("Enter a: ");
    let mut a = String::new();
    std::io::stdin().read_line(&mut a).expect("Failed to read line - a");

    println!("Enter b: ");
    let mut b = String::new();
    std::io::stdin().read_line(&mut b).expect("Failed to read line - b");

    println!("Enter c: ");
    let mut c = String::new();
    std::io::stdin().read_line(&mut c).expect("Failed to read line - c");
    
    let a: f32 = a.trim().parse().expect("Invalid number - a");
    let b: f32 = b.trim().parse().expect("Invalid number - b");
    let c: f32 = c.trim().parse().expect("Invalid number - c");
    
    let result: f32 = (a.powi(2) + b.powi(2) + c.powi(2)).sqrt();
    
    println!("{:.2}", result);

    return;
}
