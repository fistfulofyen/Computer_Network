
/*
 * 
 * Call Blocking in Circuit Switched Networks
 * 
 * Copyright (C) 2014 Terence D. Todd
 * Hamilton, Ontario, CANADA
 * todd@mcmaster.ca
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 * 
 */

/*******************************************************************************/

#include <stdio.h>
#include "simparameters.h"
#include "main.h"
#include "output.h"


double fact(double x)
{
    return tgamma(x + 1.);
}

/*******************************************************************************/

void output_progress_msg_to_screen(Simulation_Run_Ptr this_simulation_run)
{
  double percentagedone;
  Simulation_Run_Data_Ptr sim_data;

  sim_data = (Simulation_Run_Data_Ptr) simulation_run_data(this_simulation_run);

  sim_data->blip_counter++;

  if((sim_data->blip_counter >= BLIPRATE)
     ||
     (sim_data->number_of_calls_processed >= RUNLENGTH))
    {
      sim_data->blip_counter = 0;

      percentagedone =
	100 * (double) sim_data->number_of_calls_processed/RUNLENGTH;
      printf("Sim:%3.0f%%, ", 100 * (double)sim_data->run_count / sim_data->runs_required);
      printf("Run:%3.0f%% ", percentagedone);

      printf("Call Count = %ld \r", sim_data->number_of_calls_processed);

      fflush(stdout);
    }
}

/*******************************************************************************/

void output_results(Simulation_Run_Ptr this_simulation_run)
{
  double xmtted_fraction;
  Simulation_Run_Data_Ptr sim_data;

  sim_data = (Simulation_Run_Data_Ptr) simulation_run_data(this_simulation_run);

  printf("\n");

  printf("random seed = %d \n", sim_data->random_seed);
  printf("call arrival count = %ld \n", sim_data->call_arrival_count);
  printf("blocked call count = %ld \n", sim_data->blocked_call_count);

  printf("trunks = %d \n", sim_data->trunk_count);
  printf("arrival rate = %.5f \n", sim_data->arrival_rate); 
  
  printf("mean duration = %.5f \n", (double)MEAN_CALL_DURATION);
  double offered_load = MEAN_CALL_DURATION * sim_data->arrival_rate;
  printf("Offered Load (A) = %.5f \n", offered_load);

  //theoretical_erlang_B
  double accum = 0;
  for (int i = 0; i <= sim_data->trunk_count; i++) {
      accum += (double)pow(offered_load, i) / fact(i);
  }
  double theoretical_erlang_B = ((double)pow(offered_load, sim_data->trunk_count) / fact(sim_data->trunk_count)) / accum;
  printf("theoretical_erlang_B = %.5f \n", theoretical_erlang_B);

  xmtted_fraction = (double) (sim_data->call_arrival_count -
      sim_data->blocked_call_count)/sim_data->call_arrival_count;

  printf("Blocking probability = %.5f (Service fraction = %.5f)\n",
	 1-xmtted_fraction, xmtted_fraction);

  printf("\n");

  
  sim_data->writes_to_file++;
}





