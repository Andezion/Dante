fn main()
{
    let eps: f64 = 1e-4;
    let mut sum: f64 = 0.0;
    
    let mut n: u64 = 0;

    loop 
    {
        let temp: f64 = 1.0 / (n as f64 * (n as f64 + 1.0));
        if temp < eps
        {
            break;
        }
        
        sum = sum + temp;
        n += 1;
    }
    
    println!("{} {:.4}", n - 1, sum);
}
