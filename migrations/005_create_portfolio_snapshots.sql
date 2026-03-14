CREATE TABLE portfolio_snapshots (
    id BIGSERIAL PRIMARY KEY,
    user_id BIGINT NOT NULL,
    total_value DECIMAL(15,2) NOT NULL,
    snapshot_date DATE NOT NULL,

    CONSTRAINT fk_snapshot_user
        FOREIGN KEY(user_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);