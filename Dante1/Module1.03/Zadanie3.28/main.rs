use rand::random_range;

fn main()
{
    let mut number: i32;

    loop 
    {
        number = random_range(-1000 .. 1001);
        if 100 <= number && number <= 200
        {
            break;
        }
        println!("Number is: {}", number);
    }
}
