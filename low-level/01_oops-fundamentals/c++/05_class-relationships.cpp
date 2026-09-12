/*
 * 🟡 Association:
 *                🔶 Object "A" has a relationship with Object "B".
 *                🔶 A may know about or work with B, but this relationship does not imply ownership of B's lifetime.
 *
 *                🔶 Example:
 *                      🔸 Player interacts with Enemy to perform an attack.
 *
 *                🔶 Real-World Example:
 *                      🔸 A Player can attack an Enemy, but the Enemy does not belong to that Player. Both objects can exist independently.
 *
 *
 * 🟡 Aggregation:
 *                 Object "A" contains/references Object "B", but Object "B", can exist independently without Object "A".
 *
 *                 🔶 Real-World Example:
 *                      🔸 A Team contains multiple Players, but the Team does not own the Players' lifetimes.
 *                      🔸 If the Team is removed, the Players can still exist, A Player can also potentially belong to another Team.
 *
 *
 * 🟡 Composition:
 *                🔶 Object "A" owns Object "B", meaning A controls B's lifetime.
 *
 *                🔶 Real-World Example:
 *                      🔸 A Player owns an Inventory.
 *                      🔸 If the Player is destroyed, its Inventory is also destroyed.
 *                      🔸 The Inventory exists as a part of that Player.
 *
 *
 * 🟡 Dependency:
 *               🔶 Object "A" temporarily uses Object "B" to perform some operation, without maintaining B as part of A's state.
 *
 *               🔶 Real-World Example:
 *                      🔸 PaymentService needs PaymentGateway to process a payment.
 *                      🔸 PaymentService can receive PaymentGateway as a function parameter and use it for that operation without storing it.
 *
 * 🟦 Arrow Symbols:
 *      🔹 Association     ───────────────>
 *      🔹 Aggregation     ◇──────────────>
 *      🔹 Composition     ◆──────────────>
 *      🔹 Dependency      - - - - - - - ->
 *      🔹 Inheritance     ───────────────▷
 */
