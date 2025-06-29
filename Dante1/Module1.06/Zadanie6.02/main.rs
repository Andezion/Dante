fn main()
{
    let mut i: f64 = 0.0;
    
    while i < 2.0 * std::f64::consts::PI + std::f64::consts::PI / 100.0
    {
        println!("{:.4} {:.4}", i, i.sin());
        i = i + std::f64::consts::PI / 100.0;
    }
}
