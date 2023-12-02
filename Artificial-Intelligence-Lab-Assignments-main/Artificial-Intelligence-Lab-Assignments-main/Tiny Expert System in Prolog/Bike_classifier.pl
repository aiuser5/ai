bike(ktm_rc).https://github.com/Sushrut-Patil/Artificial-Intelligence-Lab-Assignments/tree/main/Lab%20Assignment%206
bike(bajaj_pulsar).
bike(royal_enfield).
bike(jawa_42).
bike(honda_cb).
bike(hero_passion).


engine_capacity(ktm_rc,373).
engine_capacity(bajaj_pulsar,200).
engine_capacity(royal_enfield,350).
engine_capacity(jawa_42,293).
engine_capacity(honda_cb,125).
engine_capacity(hero_passion,115).


weight(ktm_rc,169).
weight(bajaj_pulsar,160).
weight(royal_enfield,195).
weight(jawa_42,180).
weight(honda_cb,118).
weight(hero_passion,114).

mileage(ktm_rc, 32).
mileage(bajaj_pulsar, 36).
mileage(royal_enfield, 25).
mileage(jawa_42, 28).
mileage(honda_cb, 60).
mileage(hero_passion, 65).

is_sports(X) :- bike(X), powerful_engine(X), medium_weight(X), moderate_mileage(X).
is_cruiser(X) :- bike(X), powerful_engine(X) ,heavy_weight(X), lower_mileage(X).
is_commuter(X) :- bike(X), effi_engine(X),less_weight(X) , high_mileage(X).


powerful_engine(X) :- engine_capacity(X,E) , E >= 200.
effi_engine(X) :- engine_capacity(X,E) , E < 200.

heavy_weight(X) :- weight(X,W) , W >= 175.
medium_weight(X) :- weight(X,W) , W < 175 , W >=150.
less_weight(X) :- weight(X,W) , W < 150.

high_mileage(X) :-  mileage(X,M) , M >=50.
lower_mileage(X) :- mileage(X,M) , M < 30.
moderate_mileage(X) :- mileage(X,M), M >= 30 , M <50.


classify(X, sports) :- is_sports(X).
classify(X, cruiser) :- is_cruiser(X).
classify(X, commuter) :- is_commuter(X).
