states_needed = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

stations = {
    "1.kone": set(["id", "nv", "ut"]),
    "2.ktwo": set(["wa", "id", "mt"]),
    "3.kthree": set(["or", "nv", "ca"]),
    "4.kfour": set(["nv", "ut"]),
    "5.kfive": set(["ca", "az"])
}

final_stations = set()

while states_needed:
    best_station = None
    states_covered = set()
    for station, states_for_station in stations.items():
        covered = states_needed & states_for_station
        if len(covered) > len(states_covered):
            best_station = station
            states_covered = states_for_station
    states_needed -= states_covered
    final_stations.add(best_station)

print(final_stations)
