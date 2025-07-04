fn factorial_rec(num: i32) -> u64
{
    if num < 0
    {
        return 0;
    }
    else if num <= 1
    {
        //println!("dupa {}", num);
        return 1;
    }
    //println!("Num is: {}", num);
    (num as u64) * factorial_rec(num - 1)

}

fn main()
{
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("Incorrect input");
    let num: i32 = input.trim().parse().expect("Incorrect input");

    if 0 > num || num > 20
    {
        panic!("Too much");
    }

    println!("Result is: {}", factorial_rec(num));
}
