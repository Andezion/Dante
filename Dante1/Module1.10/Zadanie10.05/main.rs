use rand::random_range;

fn main()
{
    let mut array_original:[f64; 20] = [0.0; 20];
    let array_copy: &mut [f64; 20] = &mut array_original;

    for i in 0..20
    {
        array_copy[i] = random_range(0.0..10.0);
        print!("{:.1} ", array_copy[i]);
    }
    println!();

    for i in 0..20
    {
        print!("{:.1} ", array_original[i]);
    }
}
