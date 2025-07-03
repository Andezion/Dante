fn main()
{
    let mut array:[[i32; 10]; 10] = [[0; 10]; 10];
    let mut input: String = String::new();

    println!("Enter: ");

    for i in 0..10
    {
        for j in 0..10
        {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect input");
            array[i][j] = input.trim().parse().expect("Incorrect number");
        }
    }

    let mut result: i32 = 0;

    for i in 1..9
    {
        for j in 1..9
        {
            let mut counter: i32 = 0;

            for a in -1..2
            {
                for b in -1..2
                {
                    if a == 0 && b == 0
                    {
                        continue;
                    }

                    if array[i][j] < array[i + a][j + b]
                    {
                        counter += 1;
                    }
                }
            }

            if counter == 8
            {
                result += 1;
            }
        }
    }
    
    if result == 0
    {
        panic!("Nothing to show");
    }
    else
    {
        println!("{}", result);
    }

    for i in 1..9
    {
        for j in 1..9
        {
            let mut counter: i32 = 0;

            for a in -1..2
            {
                for b in -1..2
                {
                    if a == 0 && b == 0
                    {
                        continue;
                    }

                    if array[i][j] < array[i + a][j + b]
                    {
                        counter += 1;
                    }
                }
            }

            if counter == 8
            {
                println!("{} {}", i, j);
            }
        }
    }
}
