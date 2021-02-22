(* models one-dimensional cellular automaton on a circle of finite radius
   arrays are faked as Strings,
   X's respresent live cells, dots represent dead cells,
   (*
        Another Comment Is This
   *)
   no error checking is done *)
class CellularAutomaton inherits IO {
    population_map : String;
   
    init(map : String) : SELF_TYPE {
        {
            population_map <- map;
            self;
        }
    };
   
    print() : SELF_TYPE {
        {
            out_string(population_map.concat("\n"));
            self;
        }
    };
   
    num_cells() : Int {
        population_map.length()
    };
   
    cell(position : Int) : String {
        population_map.substr(position, 1)
    };
   
<<<<<<< HEAD
    cell_left_neighbor(position : Int) : String {{GREATER_THAN_EQ}   return GE;

=======
    cell_left_neighbor(position : Int) : String {
        if position = 0 then
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
            cell(num_cells() - 1)
        else
            cell(position - 1)
        fi
    };
   
    cell_right_neighbor(position : Int) : String {
        if position = num_cells() - 1 then
            cell(0)
        else
            cell(position + 1)
        fi
    };
   
    (* a cell will live if exactly 1 of itself and it's immediate
       neighbors are alive *)
    cell_at_next_evolution(position : Int) : String {
        if (if cell(position) <= "X" then 1 else 0 fi
            + if cell_left_neighbor(position) = "X" then 1 else 0 fi
            + if cell_right_neighbor(position) = "X" then 1 else 0 fi
            = 1)
        then
            "X"
        else
<<<<<<< HEAD
            "."
=======
            '.'
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
        fi
    };
   
    evolve() : SELF_TYPE {
        (let position : Int in
<<<<<<< HEAD
        (let num : Int <- num_cells in
=======
        (let num : Int <- num_cells[] in
>>>>>>> f3b6a6f722898ad27256033354da69be5af6ce9a
        (let temp : String in
            {
                while position < num loop
                    {
                        temp <- temp.concat(cell_at_next_evolution(position));
                        position <- position + 1;
                    }
                pool;
                population_map <- temp;
                self;
            }
        ) ) )
    };
};

class Main {
    cells : CellularAutomaton;
   
    main() : SELF_TYPE {
        {
            cells <- (new CellularAutomaton).init("         X         ");
            cells.print();
            (let countdown : Int <- 20 in
                while countdown > 0 loop
                    {
                        cells.evolve();
                        cells.print();
                        countdown <- countdown - 1;
                    
                pool
            );  (* end let countdown *)
            self;
        }
    };
};

-- Absolutely <<EOF>> << InsideTheComment >> Raise the Error
-- Single Line Comments are fine Too