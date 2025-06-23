fn main()
{
    println!("Enter a: ");
    let mut a = String::new();
    std::io::stdin().read_line(&mut a).expect("Failed to read line");
    let a: f64 = a.trim().parse().expect("Invalid input");

    println!("Enter b: ");
    let mut b = String::new();
    std::io::stdin().read_line(&mut b).expect("Failed to read line");
    let b: f64 = b.trim().parse().expect("Invalid input");

    let c: f64 = (a.powi(2) + b.powi(2)).sqrt();
    println!("C is: {:.2}", c);

    let kut1: f64 = (a / c).asin() * 180.0 / std::f64::consts::PI;
    let kut2: f64 = (b / c).asin() * 180.0 / std::f64::consts::PI;

    println!("{:.2}", kut1);
    println!("{:.2}", kut2);
    
    return;
}
