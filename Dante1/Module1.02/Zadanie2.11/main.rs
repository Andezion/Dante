fn main() {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Error");
    let number: i32 = input.trim().parse().expect("Error");

    if(number < 0 || number > 10)
    {
        println!("Incorrect input data");
    }
    else if(number == 0)
    {
        println!("zero");
    }
    else if(number == 1)
    {
        println!("jeden");
    }
    else if(number == 2)
    {
        println!("dwa");
    }
    else if(number == 3)
    {
        println!("trzy");
    }
    else if(number == 4)
    {
        println!("cztery");
    }
    else if(number == 5)
    {
        println!("piec");
    }
    else if(number == 6)
    {
        println!("szesc");
    }
    else if(number == 7)
    {
        println!("siedem");
    }
    else if(number == 8)
    {
        println!("osiem");
    }
    else if(number == 9)
    {
        println!("dziewiec");
    }
    else if(number == 10)
    {
        println!("dziesiec");
    }
}
