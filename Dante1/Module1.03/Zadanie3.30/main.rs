use rand::{rng, thread_rng, Rng};

fn main()
{
    println!("Enter: ");
    
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");
    let number: i32 = input.trim().parse().expect("Error");
    
    if 0 >= number || number > 10
    {
        panic!("Incorrect input");
    }

    let mut rng = thread_rng();
    let mut sum: f64 = 0.0;
    
    for _ in 0 .. number
    {
        let num: f64 = rng.gen_range(-5.0..=5.0);
        
        println!("{:.6}", num);
        
        sum = sum + num;
    }
    
    println!("\nSum is: {}", sum);
}
